#pragma once
#include "Engine.h"
#include "../../../Types/Private/ReplyMarkup.h"

#include "../../../Types/Common/Public/KeyboardButtonRow.h"
#include "../../../Types/Private/ReplyMarkup.h"

//begin namespace block
namespace COMMON
{
class ReplyInlineMarkup : public PRIVATE::ReplyMarkup
{
public:
	ReplyInlineMarkup();
	ReplyInlineMarkup(TArray<COMMON::KeyboardButtonRow*> rows);

	~ReplyInlineMarkup();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	TArray<COMMON::KeyboardButtonRow*> rows;
};
} //end namespace block
