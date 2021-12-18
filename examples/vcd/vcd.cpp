#include <cascade/Cascade.hpp>

class Counter : public Component
{
    DECLARE_COMPONENT(Counter);
    public:
        Counter (const char *name, COMPONENT_CTOR) : m_componentName (name){}

            Clock(clk);
            Output(int, count);

            void reset()
            {
                m_count = 0;
            }

            void update()
            {
                count = m_count++;
            }
    private:
        int m_count;
        const char *m_componentName;
};

int main()
{
    Counter auto_500("auto_500");
    auto_500.clk.generateClock(500);
    Counter manual_1000("manual_1000");
    manual_1000.clk.setManual();

    Counter manual_500("manual_500");
    manual_500.clk.divideClock(manual_1000.clk, 0.5);
    
     for (int i = 0 ; i < 5 ; i++){
         manual_1000.clk.tick();
         Sim::run(1000);
     }
}