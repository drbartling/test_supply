#ifndef RAMP_GEN_H
#define RAMP_GEN_H

/**
 * @brief Ramps voltage output over a given period
 * @details
 *
 * @param from_v starting voltage
 * @param to_v final voltage
 * @param period_s ramp period in seconds
 */
void RG_RampFromTo(double from_v, double to_v, double period_s);

#endif
