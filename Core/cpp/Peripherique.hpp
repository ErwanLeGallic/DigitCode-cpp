#ifndef PERIPHERIQUE_HPP
#define PERIPHERIQUE_HPP



class Peripherique {
public:
    enum class State {
        OFF,
        ON
    };

    Peripherique();

    virtual void Power();

    void SetState(State state);


    State GetState() const;

protected:
    State state;
};

#endif // PERIPHERIQUE_HPP
