#ifndef BASEPET_H
#define BASEPET_H
#include <iostream>
#include <string>

using namespace std;

class BasePet {
    private:
    std::string name;
    int age;
    bool is_alive
    Stats stats;

    public:
    BasePet( const std::string& name, int age = 0, int happiness = 0);//constructor
    virtual ~BasePet() = default;//destructor


    virtual void update_status();
    virtual void perform_action(const std::string& action);
    virtual bool check_alive() const;
    virtual bool check_evolution() const = 0;
    virtual std::unique_ptr<BasePet> evolve() = 0;
    virtual std::string get_type() const = 0;

    void print_status() const;
    std::string get_name() const;



};

#endif

