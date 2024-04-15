
#include<iostream>

class IErroLog
{
public:
    virtual bool reportError() = 0;

    virtual ~IErroLog(){}
};

class FileErrorLog : public IErroLog
{
    bool reportError() override
    {
        std::cout <<"Write error to a file" << std::endl;
        return true;
    }
};

class ConsoleErrorLog : public IErroLog
{
    bool reportError() override
    {
        std::cout <<"Write error to a console" << std::endl;
        return true;
    }
};

void doSomething(IErroLog & log)
{
    log.reportError();
}

int main()
{
    FileErrorLog file_log;
    ConsoleErrorLog console_log;

    doSomething(file_log);
    doSomething(console_log);
}