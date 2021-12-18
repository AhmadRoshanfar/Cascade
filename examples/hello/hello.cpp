#include <cascade/Cascade.hpp>

class Producer : public Component
{
    DECLARE_COMPONENT(Producer);
    public:
    Producer (COMPONENT_CTOR){}
    Output(char, out_ch);

    void reset()
    {
        m_ch = "Hello World\n";
    }

    void update ()
    {
        out_ch = *m_ch;
        if(*m_ch)
        m_ch++;  
    }
    private:
        const char *m_ch;
};

class Consumer : public Component
{

    DECLARE_COMPONENT(Consumer);
    public:
    Consumer (COMPONENT_CTOR){}

    Input(char, in_ch);

    void update()
    {
        if(in_ch)
        putchar(in_ch);
    };

};

int main()
{
    Producer producer;
    Consumer consumer;
    consumer.in_ch << producer.out_ch;
    Sim::run(100000);
    Sim::reset();
    Sim::run(100000);
}