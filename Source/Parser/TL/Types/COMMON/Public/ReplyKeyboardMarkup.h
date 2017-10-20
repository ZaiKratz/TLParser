#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/KeyboardButtonRow.h"

//begin namespace block
namespace COMMON
{
class ReplyKeyboardMarkup : public TLBaseObject
{
public:
	ReplyKeyboardMarkup();
	ReplyKeyboardMarkup(bool resize, bool single_use, bool selective, TArray<COMMON::KeyboardButtonRow*> rows);

	~ReplyKeyboardMarkup();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	bool Getresize() const
	{
		 return this->resize;
	}

	bool GetSingleUse() const
	{
		 return this->single_use;
	}

	bool Getselective() const
	{
		 return this->selective;
	}

	TArray<COMMON::KeyboardButtonRow*>  Getrows() const
	{
		 return this->rows;
	}

private:
	bool resize;
	 bool single_use;
	 bool selective;
	 TArray<COMMON::KeyboardButtonRow*> rows;
};
} //end namespace block
