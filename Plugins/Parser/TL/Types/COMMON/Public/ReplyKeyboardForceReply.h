#pragma once
#include "Engine.h"
#include "../../../Types/Private/ReplyMarkup.h"

#include "../../../Types/Private/ReplyMarkup.h"

//begin namespace block
namespace COMMON
{
class ReplyKeyboardForceReply : public PRIVATE::ReplyMarkup
{
public:
	ReplyKeyboardForceReply();
	ReplyKeyboardForceReply(bool single_use, bool selective);

	~ReplyKeyboardForceReply();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool single_use;
	 bool selective;
};
} //end namespace block
