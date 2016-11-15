//
//  PathSearch.hpp
//  IndoorunDemo
//
//  Created by ky on 15/11/2016.
//  Copyright © 2016 yellfun. All rights reserved.
//

#ifndef PathSearch_hpp
#define PathSearch_hpp

#include <stdio.h>
#include <list>
#include <vector>
#include "PathStructure.hpp"
#include "ThroughPathStructure.hpp"
#include "RegionPath.hpp"
#include "PathResult.hpp"
#include "PathBrief.hpp"
#include "PathUtil.hpp"

/**
 * 路径搜索
 *
 * @author Administrator
 *
 */
class PathSearch {
public:
    const static int IGNOREDES = 10;// 忽略距离，到路线投影点距离小于这一值的起始结束点将被忽略
private:
    std::vector<PathStructure> floorPath;// 楼层路径数据
    ThroughPathStructure footPath;// 人行贯通路径数据
    ThroughPathStructure carPath;// 车行贯通路径数据
    
public:
    PathSearch() {
    }
    
    PathSearch(RegionPath data) {
        setData(data);
    }
    
    /**
     * 设置数据信息
     *
     * @param data数据信息
     */
public:
    void setData(RegionPath data) {
        floorPath = data.getFloorPath();
        footPath = data.getFootPath();
        carPath = data.getCarPath();
    }
    
    /**
     * 搜索从f1层p1点到f2层p2点的最短路径（完整信息）
     *
     * @param f1起点楼层下标
     * @param p1起点坐标
     * @param f2终点楼层下标
     * @param p2终点坐标
     * @param type贯通类型，0人行，1车行
     * @return 最短路径结果集
     */
public:
    PathResult search(int f1, Position p1, int f2, Position p2, int type) {
        PathResult result;
        PathBrief brief = searchBrief(f1, p1, f2, p2, type, false);
        if (brief.isValid()) {
            result.setDistance(brief.getDistance());
            std::list<FloorPath> paths;
            int f = brief.getF();
            if (f == -1) {
                int a = brief.getA();
                int b = brief.getB();
                ThroughPathStructure structure = type == 0 ? footPath : carPath;
                std::vector<PassUnit> positions = structure.getPositions();
                PathLengthPreIndex** matrix = structure.getMatrix();
                int pro = b;
                paths.push_back(searchFloorPath(searchBrief(f2, positions[b].getPos(), p2, type, true)));
                while (b != matrix[a][b].getProIndex()) {
                    b = matrix[a][b].getProIndex();
                    if (positions[b].getFloorIndex() == positions[pro].getFloorIndex()) {
                        FloorPath fp = searchFloorPath(searchBrief(positions[b].getFloorIndex(), positions[b].getPos(),
                                                                   positions[pro].getPos(), type, true));
                        fp.setTypeId(positions[b].getUnitTypeId());
                        paths.push_back(fp);
                    }
                    pro = b;
                }
                paths.push_back(searchFloorPath(searchBrief(f1, p1, positions[a].getPos(), type, true)));
                paths.reverse();
            } else {
                paths.push_back(searchFloorPath(brief));
            }
            result.setPaths(paths);
        }
        return result;
    }
    
    /**
     * 同楼层路线搜索，根据简略信息补全完整信息
     *
     * @param brief简略信息
     * @return 完整路径搜索结果
     */
private:
    FloorPath searchFloorPath(PathBrief brief) {
        int f = brief.getF();
        int a = brief.getA();
        int b = brief.getB();
        FloorPath fp;
        fp.setFloorIndex(f);
        fp.setDistance(brief.getDistance());
        std::list<Position> list;
        if (brief.getP2().isValid())
            list.push_back(brief.getP2());
        if (brief.getPe().isValid())
            list.push_back(brief.getPe());
        searchFloorPath(f, a, b, list);
        if (brief.getPs().isValid())
            list.push_back(brief.getPs());
        if (brief.getP1().isValid())
            list.push_back(brief.getP1());
        list.reverse();
        fp.setPosition(list);
        return fp;
    }
    
    /**
     * 同楼层路径搜索，搜索结果存储到list中
     *
     * @param f楼层
     * @param a矩阵起点下标
     * @param b矩阵终点下标
     * @param list存储路径点的集合
     */
    void searchFloorPath(int f, int a, int b, std::list<Position> list) {
        std::vector<Position> positions = floorPath[f].getPositions();
        PathLengthPreIndex** matrix = floorPath[f].getMatrix();
        if (a == -1)
            return;
        list.push_back(positions[b]);
        while (b != matrix[a][b].getProIndex()) {
            b = matrix[a][b].getProIndex();
            list.push_back(positions[b]);
        }
    }
    
    /**
     * 跨楼层搜索从f1层p1点到f2层p2点的最短路径（简略信息）
     *
     * @param f1起点楼层下标
     * @param p1起点坐标
     * @param f2终点楼层下标
     * @param p2终点坐标
     * @param type贯通类型，0人行，1车行
     * @param absolutely绝对，true时强制使用跨楼层模式搜索，false时f1、f2相同会自动切换到同楼层搜索模式
     * @return 最短路径结果集（简略）
     */
public:
    PathBrief searchBrief(int f1, Position p1, int f2, Position p2, int type, bool absolutely) {
        if (f1 == f2 && !absolutely)
            return searchBrief(f1, p1, p2, type, true);
        PathBrief result;
        result.setF(-1);
        double length = DOUBLE_MAX_VALUE;
        ThroughPathStructure structure = type == 0 ? footPath : carPath;
        std::vector<PassUnit> positions = structure.getPositions();
        PathLengthPreIndex** matrix = structure.getMatrix();
        int n = sizeof(positions)/sizeof(PassUnit);
        int start = -1, end = -1;
        for (int a = 0; a < n; a++) {
            if (positions[a].getFloorIndex() == f1)
                for (int b = 0; b < n; b++) {
                    if (positions[b].getFloorIndex() == f2 && matrix[a][b].isValid()) {
                        PathBrief pb1 = searchBrief(f1, p1, positions[a].getPos(), type, true);
                        PathBrief pb2 = searchBrief(f2, positions[b].getPos(), p2, type, true);
                        if (pb1.isValid() && pb2.isValid()) {
                            double len = pb1.getDistance() + pb2.getDistance() + matrix[a][b].getLength();
                            if (len < length) {
                                length = len;
                                start = a;
                                end = b;
                            }
                        }
                    }
                }
        }
        if (start == -1)
            return result;
        result.setA(start);
        result.setB(end);
        PathBrief pb1 = searchBrief(f1, p1, positions[start].getPos(), type, true);
        PathBrief pb2 = searchBrief(f2, positions[end].getPos(), p2, type, true);
        result.setP1(pb1.getP1());
        result.setPs(pb1.getPs());
        result.setP2(pb2.getP2());
        result.setPe(pb2.getPe());
        result.setDistance(length);
        return result;
    }
    
    /**
     * 同楼层搜索f层从p1点到p2点的最短路径（简略信息）
     *
     * @param f楼层下标
     * @param p1起点坐标
     * @param p2终点坐标
     * @param type贯通类型，0人行，1车行
     * @param absolutely绝对，true时强制使用同楼层模式搜索，false时若无解会自动切换到跨楼层搜索模式
     * @return 最短路径结果集（简略）
     */
    PathBrief searchBrief(int f, Position p1, Position p2, int type, bool absolutely) {
        PathBrief result;
        result.setF(f);
        double length = 0;
        std::vector<Position> positions = floorPath[f].getPositions();
        std::vector<Segment> lines = floorPath[f].getLines();
        PathLengthPreIndex** matrix = floorPath[f].getMatrix();
        int l1 = PathUtil::findNearestLine(p1, lines);
        int l2 = PathUtil::findNearestLine(p2, lines);
        PositionDistance s = PathUtil::p2lDes(p1, lines[l1]);
        PositionDistance e = PathUtil::p2lDes(p2, lines[l2]);
        if (s.getDistance() > IGNOREDES) {
            length += s.getDistance();
            result.setP1(p1);
        }
        if (e.getDistance() > IGNOREDES) {
            length += e.getDistance();
            result.setP2(p2);
        }
        Position ps = s.getPosition();
        Position pe = e.getPosition();
        result.setPs(ps);
        result.setPe(pe);
        if (l1 != l2) {
            int pa = PathUtil::findPositionIndex(lines[l1].getEndPointOne(), positions);
            int pb = PathUtil::findPositionIndex(lines[l1].getEndPointTwo(), positions);
            int pc = PathUtil::findPositionIndex(lines[l2].getEndPointOne(), positions);
            int pd = PathUtil::findPositionIndex(lines[l2].getEndPointTwo(), positions);
            double sa = PathUtil::p2pDes(ps, positions[pa]);
            double sb = PathUtil::p2pDes(ps, positions[pb]);
            double sc = PathUtil::p2pDes(pe, positions[pc]);
            double sd = PathUtil::p2pDes(pe, positions[pd]);
            double len = 999999999999;
            int start = -1, end = -1;
            if (matrix[pa][pc].isValid()) {
                len = sa + sc + matrix[pa][pc].getLength();
                start = pa;
                end = pc;
            }
            if (matrix[pa][pd].isValid() && sa + sd + matrix[pa][pd].getLength() < len) {
                len = sa + sd + matrix[pa][pd].getLength();
                start = pa;
                end = pd;
            }
            if (matrix[pb][pc].isValid() && sb + sc + matrix[pb][pc].getLength() < len) {
                len = sb + sc + matrix[pb][pc].getLength();
                start = pb;
                end = pc;
            }
            if (matrix[pb][pd].isValid() && sb + sd + matrix[pb][pd].getLength() < len) {
                len = sb + sd + matrix[pb][pd].getLength();
                start = pb;
                end = pd;
            }
            if (start != -1) {
                result.setA(start);
                result.setB(end);
                if (PathUtil::p2pDes(ps, positions[start]) < 1)
                    result.setPs(Position());
                if (PathUtil::p2pDes(pe, positions[end]) < 1)
                    result.setPe(Position());
                length += len;
            } else
                return absolutely ? PathBrief() : searchBrief(f, p1, f, p2, type, true);
        } else {
            result.setA(-1);
            length += PathUtil::p2pDes(ps, pe);
        }
        result.setDistance(length);
        return result;
    }
};


#endif /* PathSearch_hpp */
