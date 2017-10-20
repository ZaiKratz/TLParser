#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageMediaAuto : public TLBaseObject
{
public:
	InputBotInlineMessageMediaAuto();
	InputBotInlineMessageMediaAuto(FString caption, TLBaseObject* reply_markup);

	~InputBotInlineMessageMediaAuto();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	FString Getcaption() const
	{
		 return this->caption;
	}

	TLBaseObject*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	FString caption;
	 TLBaseObject* reply_markup;
};
} //end namespace block
