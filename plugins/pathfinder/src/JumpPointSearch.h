/* Copyright (c) 2012 Gillis Van Ginderachter <supergillis@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *     http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef JUMPPOINTSEARCH_H
#define JUMPPOINTSEARCH_H

#include "PriorityQueue.h"

#include <MiniMapPluginInterface.h>
#include <Position.h>

#include <QtGlobal>
#include <QList>
#include <QPair>

struct Position2D {
    Position2D(): x(0), y(0) {}
    Position2D(quint16 x_, quint16 y_): x(x_), y(y_) {}

    quint16 x;
    quint16 y;
};

struct JpsNode {
    JpsNode* parent;

    quint16 x;
    quint16 y;

    quint32 g;
    quint32 h;
};

class JpsNodeComparator {
public:
    bool operator() (const JpsNode* a, const JpsNode* b) const {
        return (a->g + a->h) < (b->g + b->h);
    }
};

class JumpPointSearch {
public:
    JumpPointSearch(MiniMapFloorInterface* floor, quint16 x, quint16 y, quint16 ex, quint16 ey);
    ~JumpPointSearch();

    QList<Position> checkpoints();
    QList<Position> positions();

private:
    bool isOpen(quint16 x, quint16 y);

    void identifySuccessors(JpsNode* node);
    void createSuccessor(quint16 x, quint16 y, JpsNode* parent);

    void findNeighbours(JpsNode* node, QList<Position2D>& neighbors);
    Position2D jump(quint16 x, quint16 y, quint16 px, quint16 py);

    JpsNode* nodeOnPosition(quint16 x, quint16 y);

    quint32 heuristic(quint16 x, quint16 y);

    MiniMapFloorInterface* floor_;
    quint16 startX_;
    quint16 startY_;
    quint16 endX_;
    quint16 endY_;

    QList<JpsNode*> nodes_;
    QList<Position2D> closed_;
    PriorityQueue<JpsNode*, JpsNodeComparator> open_;
};

#endif
