// ***********************************************************************
// Filename         : Timestamp.h
// Author           : XULI
// Created          : 2020-10-13
// Description      : 时间戳函数
// ***********************************************************************

#ifndef XL_BASE_TIMESTAMP_H
#define XL_BASE_TIMESTAMP_H

#include <xlpublic/base/copyable.h>
#include <xlpublic/base/Types.h>
#include <string>
#include <stdio.h>
#include <boost/operators.hpp>
using namespace std;

namespace XL
{
    class Timestamp : public XL::copyable, public boost::less_than_comparable<Timestamp>
    {
    public:
        Timestamp() : microSecondsSinceEpoch_(0) {}
        explicit Timestamp(int64_t microSecondsSinceEpoch);

        void swap(Timestamp &that)
        {
            std::swap(microSecondsSinceEpoch_, that.microSecondsSinceEpoch_);
        }

        string toString() const;
        string toFromattedString() const;

        bool valid() const { return microSecondsSinceEpoch_ > 0; }
        int64_t microSecondsSinceEpoch() const { return microSecondsSinceEpoch_; }
        time_t seconsSinceEpoch() const
        {
            return static_cast<time_t>(microSecondsSinceEpoch_ / kMicroSecondsPerSecond);
        }

        static Timestamp now();
        static Timestamp invalid();
        static const int kMicroSecondsPerSecond = 1000 * 1000;

    private:
        int64_t microSecondsSinceEpoch_;
    };

    inline bool operator<(Timestamp lhs, Timestamp rhs)
    {
        return lhs.microSecondsSinceEpoch() < rhs.microSecondsSinceEpoch();
    }

    inline bool operator==(Timestamp lhs, Timestamp rhs)
    {
        return lhs.microSecondsSinceEpoch() == rhs.microSecondsSinceEpoch();
    }

    inline double timeDifference(Timestamp high, Timestamp low)
    {
        int64_t diff = high.microSecondsSinceEpoch() - low.microSecondsSinceEpoch();
        return static_cast<double>(diff) / Timestamp::kMicroSecondsPerSecond;
    }

    inline Timestamp addTime(Timestamp timestamp, double seconds)
    {
        int64_t delta = static_cast<int64_t>(seconds * Timestamp::kMicroSecondsPerSecond);
        return Timestamp(timestamp.microSecondsSinceEpoch() + delta);
    }
} // namespace XL

#endif