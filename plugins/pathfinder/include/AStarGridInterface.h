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

#ifndef ASTARGRIDINTERFACE_H
#define ASTARGRIDINTERFACE_H

#include <QtGlobal>

class AStarGridInterface {
public:
    virtual void forEachNeighbour(quint16 x, quint16 y, quint8 z, std::function<void (quint16, quint16, quint8, quint8)> function) = 0;
};

#endif
