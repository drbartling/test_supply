#ifndef EVENT_HANDLER_H
#define EVENT_HANDLER_H

#include <stdbool.h>

/**
 * @brief Function pointer to user provided event checker function
 * @details Provided function shall return a boolean result indicating an event
 *     has occurred (true) or that an event has not occurred (false).  The
 *     function shall take no arguments.  This function will provide a trigger
 *     to execute the EventExec() function.
 *
 * @param  void
 * @return true - Event has occurred
 * @return false - Event has not occurred
 */
typedef bool (*EventChecker_t)(void);


/**
 * @brief Function pointer to user provided event execution function
 * @details Provided function shall take no arguments and return no value.  The
 *     EventExec() function shall execute when the EventChecker FIRST returns
 *     true.  It shall not execute again until the user re-arms the event.
 *
 * @param  void
 * @return void
 */
typedef void (*EventExec_t)(void);

void EventCheckerSet(EventChecker_t);
void EventExecSet(EventExec_t);
bool EventArm(void);
void EventClear(void);
bool EventHasOccurred(void);

#endif
