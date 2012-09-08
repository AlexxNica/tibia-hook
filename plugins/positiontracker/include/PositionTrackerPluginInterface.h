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

#ifndef POSITIONTRACKERPLUGININTERFACE_H
#define POSITIONTRACKERPLUGININTERFACE_H

#include <QtPlugin>

class PositionTrackerPluginInterface {
public:
    virtual ~PositionTrackerPluginInterface() {}

    virtual Position position() const = 0;

    virtual void connectPositionChanged(QObject* object, const char* slot, Qt::ConnectionType type = Qt::AutoConnection) = 0;
    virtual void disconnectPositionChanged(QObject* object, const char* slot) = 0;
};

Q_DECLARE_INTERFACE(PositionTrackerPluginInterface, "PositionTrackerPluginInterface")

#endif
