#pragma once

#include <cstdint>

struct IAudioPlayerCallback
{
    virtual void AppendFrameClock(double frame_clock) = 0;
};

struct IAudioPlayer
{
    virtual ~IAudioPlayer() = default;
    virtual void SetCallback(IAudioPlayerCallback* callback) = 0;

    virtual void InitializeThread() = 0;
    virtual void DeinitializeThread() = 0;

    virtual void WaveOutReset() = 0;
    virtual void Close() = 0;
    virtual bool Open(int bytesPerSample, int channels, int* samplesPerSec) = 0;

    virtual void SetVolume(double volume) = 0;
    virtual double GetVolume() const = 0;

    virtual void WaveOutPause() = 0;
    virtual void WaveOutRestart() = 0;

    virtual bool WriteAudio(uint8_t* write_data, int64_t write_size) = 0;
};
