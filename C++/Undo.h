#pragma once
#pragma once

#include "Tutorial.h"
#include "Repository.h"

/*
Generic class for an undo action.
For each type of action (add, delete, update), a new class will be created, inheriting from this UndoAction.
*/
class UndoAction
{
public:
	virtual void executeUndo() = 0;
	virtual ~UndoAction() {};
};

class UndoAdd : public UndoAction
{
private:
	Tutorial addedTutorial;
	Repository& repo;	// we keep a reference to the repository to be able to undo the action
public:
	UndoAdd(Repository& _repo, const Tutorial& t) : repo{ _repo }, addedTutorial{ t } {}

	/*
	For the add operation, the reverse operation that must be executed is "remove".
	*/
	void executeUndo() override
	{
		int i = this->repo.getPosRepo(addedTutorial.getTitle(), addedTutorial.getPresenter());
		this->repo.deleteTutorial(i);
	}
};

class UndoRemove : public UndoAction
{
private:
	Tutorial deletedTutorial;
	Repository& repo;
public:
	UndoRemove(Repository& _repo, const Tutorial& t) : repo{ _repo }, deletedTutorial{ t } {}

	void executeUndo() override
	{
		this->repo.addTutorial(deletedTutorial);
	}
};

class UndoUpdate : public UndoAction
{
private:
	Tutorial updatedTutorial;
	Repository& repo;
public:
	UndoUpdate(Repository& _repo,const Tutorial& t) : repo{_repo},updatedTutorial{t}{}

	void executeUndo() override
	{
		this->repo.updateTutorial(repo.getPosRepo(updatedTutorial.getTitle(), updatedTutorial.getPresenter()), updatedTutorial.getTitle(), updatedTutorial.getPresenter(), updatedTutorial.getDuration()->getMinutes(), updatedTutorial.getDuration()->getSeconds(), updatedTutorial.getLikes(), updatedTutorial.getSource());
	}
};