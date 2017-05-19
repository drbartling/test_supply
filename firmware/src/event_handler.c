
#include "event_handler.h"
#include "tmr2.h"
#include <stddef.h>

EventChecker_t EH_EventChecker;
EventExec_t    EH_EventExec;
bool           EH_eventArmed;

void EventCheckerSet(EventChecker_t EventChecker)
{
    EH_EventChecker = EventChecker;
}

void EventExecSet(EventExec_t EventExec)
{
    EH_EventExec = EventExec;
}

bool EventArm(void)
{
    bool err = false;
    if(NULL == EH_EventChecker)
    {
        err = true;
        return err;
    }
    if(NULL == EH_EventExec)
    {
        err = true;
        return err;
    }

    EH_eventArmed = true;
    return err;
}

bool EventHasOccurred(void)
{
    return !EH_eventArmed;
}

void TMR2_CallBack(void)
{
    if(false == EH_eventArmed)
    {
        return;
    }

    if(EH_EventChecker())
    {
        EH_eventArmed = false;
        EH_EventExec();
    }
}
