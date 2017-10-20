#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/KeyboardButtonRow.h"

//begin namespace block
namespace COMMON
{
class ReplyInlineMarkup : public TLBaseObject
{
public:
	ReplyInlineMarkup();
	ReplyInlineMarkup(TArray<COMMON::KeyboardButtonRow*> rows);

	~ReplyInlineMarkup();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<COMMON::KeyboardButtonRow*>  Getrows() const
	{
		 return this->rows;
	}

private:
	TArray<COMMON::KeyboardButtonRow*> rows;
};
} //end namespace block
