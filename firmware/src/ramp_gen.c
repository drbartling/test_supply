
#include "ramp_gen.h"
#include "tmr2.h"
#include "ad5060.h"
#include "unit_conversion.h"

/* Terms
 * vps - Volts Per Second
 */

#define RESISTANCE_MIN (10 * K_OHM)
#define RESISTANCE_MAX (20 * K_OHM)

#define VOLTS_HIGH (5.0)
#define VOLTS_LOW (-5.0)

#ifndef RAMP_CAPCITANCE
#define RAMP_CAPCITANCE (50e-9)
#endif

#define RG_TIMER_PERIOD_US (100L)
#define RG_TIMER_FREQUENCY_HZ ((1.0 / RG_TIMER_PERIOD_US) * ((double) US_PER_S))

void PRPS_RampRateSet(double vps)
{
    double current_a     = vps * CAPACITANCE;
    double voltageDrop_v = 5.0;
    double resistance_o  = voltageDrop_v / current_a;
    // Convert to DAC values for voltage drop potentiometer and programming varistor.
    // Combine settings with the settings in the other channel (since they are chained together on the bus).
    // Write output to DACs.
}

void RG_RampFromTo(double from_v, double to_v, double period_s)
{
    double delta_v            = to_v - from_v;
    double v_per_s            = delta_v / period_s;
    double v_per_timer_period = v_per_s / RG_TIMER_FREQUENCY_HZ;
    int    timer_periods      = period_s * RG_TIMER_FREQUENCY_HZ;
    int    i;
    while(false == TMR2_GetElapsedThenClear());
    for (i = 0; i < timer_periods; ++i)
    {
        double v = from_v + (v_per_timer_period * i);
        AD5060_OutputWrite_v(v);
        while (false == TMR2_GetElapsedThenClear());
    }
    AD5060_OutputWrite_v(to_v);
}
