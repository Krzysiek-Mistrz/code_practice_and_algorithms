using System;
using System.Collections.Concurrent;


public static class TelemetryBuffer
{
    public static byte[] ToBuffer(long reading)
    {
        byte[] buffer = new byte[9];
        byte[] payload;
        byte prefix;

        if (reading < int.MinValue)
        {
            prefix = 248; // 256 - 8
            payload = BitConverter.GetBytes(reading);
        }
        else if (reading < short.MinValue) 
        {
            prefix = 252; // 256 - 4
            payload = BitConverter.GetBytes((int)reading);
        }
        else if (reading < 0)
        {
            prefix = 254; // 256 - 2
            payload = BitConverter.GetBytes((short)reading);
        }
        else if (reading <= ushort.MaxValue) // 0 - 65535
        {
            prefix = 2;
            payload = BitConverter.GetBytes((ushort)reading);
        }
        else if (reading <= int.MaxValue)
        {
            prefix = 252; // 256 - 4 (int)
            payload = BitConverter.GetBytes((int)reading);
        }
        else if (reading <= uint.MaxValue)
        {
            prefix = 4;
            payload = BitConverter.GetBytes((uint)reading);
        }
        else
        {
            prefix = 248; // 256 - 8
            payload = BitConverter.GetBytes(reading);
        }

        buffer[0] = prefix;
        Array.Copy(payload, 0, buffer, 1, payload.Length);
        
        return buffer;
    }

    public static long FromBuffer(byte[] buffer)
    {
        sbyte prefix = (sbyte)buffer[0];

        return prefix switch
        {
            2 => BitConverter.ToUInt16(buffer, 1),
            4 => BitConverter.ToUInt32(buffer, 1),
            -2 => BitConverter.ToInt16(buffer, 1),
            -4 => BitConverter.ToInt32(buffer, 1),
            -8 => BitConverter.ToInt64(buffer, 1),
            _ => 0
        };
    }
}
