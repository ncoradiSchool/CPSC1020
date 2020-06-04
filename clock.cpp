#include <iostream>
#include <ctime>
#include "unistd.h"

const size_t time_buff = 1000;
const int timer = 5;

int main(int argc, char const *argv[])
{
    time_t now;
    struct tm local_now;
    char now_string[time_buff];

    std::cout << "I'm a clock! I'll terminate in " << timer << " seconds!"
        << std::endl
        << "Or hit Ctrl+C!" << std::endl;

    for(int i = 0; i < timer; i++)
    {
        time(&now);
        localtime_r(&now, &local_now);
        //don't worrk, the 20 in front wont be a problem until Y3k
        strftime(now_string, time_buff, "%a, %B %d 20%EC, %H:%M:%S", &local_now);
        std::cout << "The current local time is: "
            << now_string
            << "\r"
            << std::flush;
        sleep(1);
    }

    std::cout<<std::endl;

    return 0;
}
