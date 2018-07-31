#ifdef _WIN32
	#include <winsock2.h>
	#include <time.h>
#else
	#include <sys/time.h>
#endif
 
unsigned long long GetCurrentTimeMsec()
{
#ifdef _WIN32
		struct timeval tv;
		time_t clock;
		struct tm tm;
		SYSTEMTIME wtm;
 
		GetLocalTime(&wtm);
		tm.tm_year = wtm.wYear - 1900;
		tm.tm_mon = wtm.wMonth - 1;
		tm.tm_mday = wtm.wDay;
		tm.tm_hour = wtm.wHour;
		tm.tm_min = wtm.wMinute;
		tm.tm_sec = wtm.wSecond;
		tm.tm_isdst = -1;
		clock = mktime(&tm);
		tv.tv_sec = clock;
		tv.tv_usec = wtm.wMilliseconds * 1000;
		return ((unsigned long long)tv.tv_sec * 1000 + (unsigned long long)tv.tv_usec / 1000);
#else
        struct timeval tv;
        gettimeofday(&tv,NULL);
        return ((unsigned long long)tv.tv_sec * 1000 + (unsigned long long)tv.tv_usec / 1000);
#endif
    }
    

//Fetch the token from string
    		char demi[] = " ,;";
		char *next_token = NULL; 
		char *token = NULL;
		token = strtok_s(logSymbols, demi, &next_token);
		while (token != nullptr)
		{
			//save the token
			m_InterestedSymbols.emplace(token);
			MyLogger::Write("Interested Symbol: %s\n", token);
			//get next token
			token = strtok_s(NULL, demi, &next_token);
		}
