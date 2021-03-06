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

#ifndef MEMORYINTERFACE_H
#define MEMORYINTERFACE_H

#include <QtGlobal>

typedef quintptr MemoryLocation;

class MemoryInterface {
public:
    virtual MemoryLocation rebase(MemoryLocation address) const = 0;

    virtual quint8 readUInt8(MemoryLocation location) const = 0;
    virtual quint16 readUInt16(MemoryLocation location) const = 0;
    virtual quint32 readUInt32(MemoryLocation location) const = 0;
    virtual quint64 readUInt64(MemoryLocation location) const = 0;

    virtual const char* readRawString(MemoryLocation location) const = 0;
    virtual QString readString(MemoryLocation location) const = 0;
};

#endif
