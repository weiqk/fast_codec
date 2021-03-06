#ifndef FAST_CODEC_ENCODER_HEADER
#define FAST_CODEC_ENCODER_HEADER

#include "common_defs.h"

namespace fast_codec
{
	struct Encoder
	{
		Encoder()
		{
			data_.reserve(FAST_MAX_MSG_SIZE);
		}

		void Reset()
		{
			data_.clear();
		}

		buffer& Data()
		{
			return data_;
		}

		const buffer& Data() const
		{
			return data_;
		}

		size_t Size() const
		{
			return data_.size();
		}

		void Resize(size_t size)
		{
			data_.resize(size);
		}

		buffer data_;
	};

	void write_byte(int, Encoder& c, std::uint8_t b);
	void write_byte(Encoder& c, std::uint8_t b);
	void write_byte(Encoder& c, std::uint8_t b, std::uint32_t count);
	void write(Encoder& c, std::uint32_t msg_seq_num);
}

#endif
