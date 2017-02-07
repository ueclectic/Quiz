#include <iostream>
#include <memory>
#include "question.h"
#include "questionTF.h"
#include "questionSA.h"
#include "questionmc.h"
#include "game.h"

using namespace std;
using namespace quiz;

int main() {

	unique_ptr<Game> game(new Game());
	game->start();

	/*try {

		shared_ptr<QuestionMC> question( new QuestionMC("question MC", "B", 10));
		question->addOption("option1");
		question->addOption("option2");
		question->addOption("option3");
		question->addOption("option4");

		vector<shared_ptr<Question>> q;
		q.push_back(question);
		q.push_back(shared_ptr<QuestionSA>(new QuestionSA("question SA", "answer", 5)));
		q.push_back(shared_ptr<QuestionTF>(new QuestionTF("question TF", "true", 3)));

		for (auto item: q) {
			cout <<endl<< item->print() << endl;
			Response response = item->check("C");
			cout << response.MESSAGE << response.VALUE << endl;
		}
	}
	catch(...)
	{
		cout << "error" << endl;
	}*/

}