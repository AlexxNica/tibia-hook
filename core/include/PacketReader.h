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

#ifndef PACKETREADER_H
#define PACKETREADER_H

#include <QtGlobal>
#include <QByteArray>
#include <QString>

#include <assert.h>

#include <Packet.h>

#define PACKET_END_OF_FILE "reached the end of the buffer"

class PacketReader {
public:
    PacketReader(const Packet& packet): data_(packet.data()), position_(0) {}
    PacketReader(const QByteArray& data): data_(data), position_(0) {}
    virtual ~PacketReader() {}

    inline const QByteArray& data() const { return data_; }

    inline quint16 position() const { return position_; }
    inline void setPosition(quint16 position) { position_ = position; }

    inline void skip(quint16 count) { position_ += count; }
    inline bool has(quint16 count) const { return data_.length() - position_ >= count; }

    inline quint8 peekU8() const { return peek<quint8, 1>(); }
    inline quint16 peekU16() const { return peek<quint16, 2>(); }
    inline quint32 peekU32() const { return peek<quint32, 4>(); }
    inline quint64 peekU64()  const{ return peek<quint64, 8>(); }

    inline quint8 readU8() { return read<quint8, 1>(); }
    inline quint16 readU16() { return read<quint16, 2>(); }
    inline quint32 readU32() { return read<quint32, 4>(); }
    inline quint64 readU64() { return read<quint64, 8>(); }

    QString readString() {
        quint16 length = readU16();
        assert(has(length) && PACKET_END_OF_FILE);

        // The data contains the raw ASCII string
        QString value = QString::fromAscii((const char*) (data_.data() + position_), length);
        position_ += length;
        return value;
    }

protected:
    const QByteArray data_;
    quint16 position_;

private:
	template<typename T, int size>
    inline T peek() const {
        assert(has(size) && PACKET_END_OF_FILE);
        return *((T*) (data_.data() + position_));
    }

	template<typename T, int size>
    inline T read() {
		T value = peek<T, size>();
		position_ += size;
        return value;
    }
};

#endif
