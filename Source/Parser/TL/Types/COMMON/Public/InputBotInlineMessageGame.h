#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputBotInlineMessageGame : public TLBaseObject
{
public:
	InputBotInlineMessageGame();
	InputBotInlineMessageGame(TLBaseObject* reply_markup);

	~InputBotInlineMessageGame();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TLBaseObject*  GetReplyMarkup() const
	{
		 return this->reply_markup;
	}

private:
	TLBaseObject* reply_markup;
};
} //end namespace block
