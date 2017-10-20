#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class ReplyKeyboardHide : public TLBaseObject
{
public:
	ReplyKeyboardHide();
	ReplyKeyboardHide(bool selective);

	~ReplyKeyboardHide();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getselective() const
	{
		 return this->selective;
	}

private:
	bool selective;
};
} //end namespace block
