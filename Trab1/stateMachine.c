#include <stdio.h>
//Different state of ATM machine
typedef enum
{
    Idle_State,
    Card_Inserted_State,
    Pin_Eentered_State,
    Option_Selected_State,
    Amount_Entered_State,
} eSystemState;
//Different type events
typedef enum
{
    Card_Insert_Event,
    Pin_Enter_Event,
    Option_Selection_Event,
    Amount_Enter_Event,
    Amount_Dispatch_Event
} eSystemEvent;
//Prototype of eventhandlers
eSystemState AmountDispatchHandler(void)
{
    printf("Iddle_state %d\n", Idle_State);
    return Idle_State;
}
eSystemState EnterAmountHandler(void)
{
    printf("Amount_Entered_State %d\n", Amount_Entered_State);
    return Amount_Entered_State;
}
eSystemState OptionSelectionHandler(void)
{
    printf("Option_Selected_State %d\n", Option_Selected_State);
    return Option_Selected_State;
}
eSystemState EnterPinHandler(void)
{
    printf("Pin_Eentered_State %d\n", Pin_Eentered_State);
    return Pin_Eentered_State;
}
eSystemState InsertCardHandler(void)
{
    printf("Card_Inserted_State %d\n", Card_Inserted_State);
    return Card_Inserted_State;
}
int main(int argc, char *argv[])
{
    eSystemState eNextState = Idle_State;
    eSystemEvent eNewEvent;
    
    int vector[1000] = { 5, 2, 5, 5, 2, 4, 1, 3, 3, 1, 1, 1, 5, 1, 2, 2, 1, 4, 3, 5, 2, 5, 5, 1, 2, 1, 3, 4, 1, 4, 4, 5, 5, 4, 4, 1, 2, 5, 3, 4, 5, 4, 5, 5, 5, 1, 1, 5, 5, 3, 4, 2, 3, 4, 2, 5, 5, 4, 4, 5, 3, 3, 4, 2, 1, 3, 3, 3, 2, 1, 2, 2, 4, 1, 1, 3, 2, 1, 3, 2, 4, 2, 3, 2, 1, 4, 1, 5, 3, 4, 4, 5, 1, 3, 2, 2, 5, 4, 4, 2, 4, 1, 3, 3, 2, 4, 1, 4, 4, 3, 5, 3, 4, 2, 4, 5, 5, 5, 4, 3, 4, 3, 2, 5, 5, 4, 1, 5, 2, 5, 1, 1, 5, 4, 3, 2, 2, 3, 5, 1, 1, 4, 3, 5, 5, 2, 4, 4, 2, 2, 2, 5, 4, 3, 4, 3, 2, 4, 3, 3, 4, 3, 4, 4, 2, 2, 5, 3, 4, 4, 4, 5, 2, 2, 4, 1, 3, 2, 5, 4, 3, 1, 4, 2, 4, 2, 5, 5, 1, 2, 3, 4, 4, 1, 2, 5, 2, 1, 3, 1, 5, 2, 5, 1, 3, 3, 2, 1, 4, 1, 5, 2, 2, 3, 3, 1, 4, 2, 5, 4, 3, 3, 3, 2, 4, 5, 2, 1, 5, 5, 1, 5, 1, 1, 5, 4, 4, 2, 4, 3, 2, 4, 4, 4, 1, 2, 4, 5, 4, 4, 4, 2, 1, 1, 3, 4, 5, 5, 5, 5, 4, 5, 4, 4, 1, 4, 2, 4, 5, 1, 1, 2, 4, 5, 1, 5, 1, 4, 4, 4, 3, 3, 5, 3, 4, 3, 2, 3, 2, 1, 3, 5, 1, 2, 4, 1, 1, 1, 4, 1, 2, 5, 2, 5, 4, 2, 4, 5, 1, 3, 4, 3, 5, 4, 1, 3, 1, 3, 1, 3, 4, 3, 3, 4, 5, 2, 5, 1, 2, 4, 1, 3, 3, 3, 3, 2, 5, 1, 1, 5, 3, 4, 3, 2, 3, 3, 4, 3, 1, 5, 1, 4, 3, 3, 2, 2, 4, 1, 3, 5, 4, 3, 3, 2, 5, 5, 3, 5, 1, 4, 4, 4, 3, 2, 5, 5, 4, 4, 3, 4, 3, 3, 2, 1, 5, 4, 2, 3, 5, 4, 3, 4, 2, 1, 5, 2, 1, 3, 1, 1, 2, 5, 5, 4, 1, 4, 4, 5, 3, 1, 4, 1, 3, 1, 1, 3, 4, 3, 5, 4, 2, 3, 2, 4, 4, 2, 5, 4, 5, 1, 5, 1, 5, 4, 5, 1, 3, 3, 5, 1, 3, 3, 2, 1, 3, 3, 3, 2, 5, 3, 5, 2, 1, 2, 5, 4, 3, 5, 3, 3, 5, 3, 3, 5, 1, 2, 5, 4, 5, 5, 4, 2, 2, 5, 3, 5, 3, 5, 2, 3, 3, 2, 4, 3, 4, 4, 2, 1, 4, 4, 3, 4, 1, 1, 3, 2, 3, 3, 5, 2, 2, 4, 3, 3, 4, 1, 3, 1, 5, 5, 3, 2, 1, 2, 5, 4, 5, 1, 5, 3, 5, 3, 1, 5, 4, 4, 2, 1, 1, 1, 2, 2, 5, 5, 5, 3, 5, 3, 3, 5, 2, 1, 2, 3, 2, 1, 2, 1, 1, 2, 4, 1, 5, 5, 1, 3, 3, 2, 3, 4, 3, 5, 1, 2, 4, 5, 4, 4, 3, 2, 3, 5, 2, 4, 2, 3, 4, 4, 4, 5, 1, 3, 5, 5, 3, 5, 2, 5, 2, 5, 4, 4, 4, 4, 5, 3, 4, 3, 1, 1, 5, 3, 5, 1, 1, 2, 4, 5, 5, 3, 4, 5, 1, 4, 4, 3, 4, 1, 3, 5, 1, 1, 4, 4, 5, 3, 2, 3, 1, 2, 3, 5, 4, 2, 1, 5, 3, 5, 4, 3, 3, 3, 2, 3, 2, 1, 1, 5, 2, 4, 5, 2, 4, 3, 1, 4, 1, 2, 1, 1, 4, 3, 5, 3, 5, 1, 2, 3, 5, 1, 5, 3, 3, 2, 5, 4, 3, 1, 4, 5, 4, 4, 1, 3, 1, 2, 1, 1, 4, 1, 2, 2, 4, 2, 4, 4, 2, 5, 1, 2, 1, 1, 4, 3, 3, 4, 2, 5, 4, 1, 4, 2, 4, 5, 4, 5, 2, 5, 1, 5, 1, 2, 1, 4, 4, 5, 3, 5, 5, 4, 2, 5, 4, 1, 3, 2, 4, 4, 2, 3, 5, 5, 4, 3, 5, 3, 3, 1, 3, 4, 1, 3, 1, 2, 2, 4, 1, 4, 4, 1, 2, 5, 5, 1, 1, 2, 2, 4, 1, 3, 1, 5, 3, 5, 3, 3, 3, 1, 4, 5, 4, 4, 2, 4, 5, 3, 2, 1, 1, 1, 1, 3, 1, 5, 3, 1, 2, 5, 5, 2, 2, 5, 2, 5, 5, 5, 2, 2, 5, 5, 2, 3, 4, 3, 2, 3, 1, 4, 4, 1, 4, 4, 4, 5, 4, 2, 5, 5, 1, 4, 2, 3, 4, 3, 3, 3, 2, 4, 5, 2, 4, 1, 4, 2, 3, 1, 5, 3, 4, 3, 4, 3, 1, 3, 2, 4, 4, 1, 4, 5, 5, 5, 2, 3, 3, 4, 1, 5, 3, 5, 1, 2, 1, 5, 4, 4, 5, 3, 2, 3, 1, 1, 5, 1, 3, 2, 5, 1, 2, 4, 5, 1, 3, 2, 4, 1, 1, 4, 5, 4, 4, 5, 5, 5, 4, 3, 3, 4, 5, 4, 2, 1, 5, 2, 1, 2, 3, 1, 3, 4, 4, 3, 5, 2, 4, 4, 2, 5, 2, 2, 3, 1, 1, 2, 5, 5, 5, 3, 3, 4, 2, 5, 5, 1, 1, 1, 2, 3, 1, 4, 2, 5, 2, 2, 2, 5, 5, 4, 5, 2, 5, 2, 2, 1, 3, 2, 5, 3, 4, 3, 2, 1, 2, 1, 1, 3, 1, 2, 5, 1, 1, 1, 1, 2, 2, 3, 2, 2, 1, 1, 3, 5, 3, 5, 5, 1, 1, 5, 3 };
    int sizeVector = 1000;
    int index = 0;
    while(index < 1000)
    {
        //Read system Events
        //eSystemEvent eNewEvent = ReadEvent();
        switch(vector[index])
        {
        case Idle_State:
        {
            if(Card_Insert_Event == vector[index])
            {
                eNextState = InsertCardHandler();
            }
        }
        break;
        case Card_Inserted_State:
        {
            if(Pin_Enter_Event == vector[index])
            {
                eNextState = EnterPinHandler();
            }
        }
        break;
        case Pin_Eentered_State:
        {
            if(Option_Selection_Event == vector[index])
            {
                eNextState = OptionSelectionHandler();
            }
        }
        break;
        case Option_Selected_State:
        {
            if(Amount_Enter_Event == vector[index])
            {
                eNextState = EnterAmountHandler();
            }
        }
        break;
        case Amount_Entered_State:
        {
            if(Amount_Dispatch_Event == vector[index])
            {
                eNextState = AmountDispatchHandler();
            }
        }
        break;
        default:
            break;
        }
        index = index + 1;
    }
    return 0;
}
