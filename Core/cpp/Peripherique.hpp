#ifndef PERIPHERIQUE_HPP
#define PERIPHERIQUE_HPP

enum State {
	OFF, ON
};

class Peripherique {
public:

	Peripherique();

	virtual void Power();

	void SetState(State state);

	State GetState();

protected:
	State state = OFF;
};

#endif // PERIPHERIQUE_HPP
