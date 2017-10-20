#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputMediaGame : public TLBaseObject
{
public:
	InputMediaGame();
	InputMediaGame(TLBaseObject* id);

	~InputMediaGame();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  Getid() const
	{
		 return this->id;
	}

private:
	TLBaseObject* id;
};
} //end namespace block
