#pragma once
#include "Engine.h"
#include "../../../Types/Private/ReplyMarkup.h"

#include "../../../Types/Private/ReplyMarkup.h"

//begin namespace block
namespace COMMON
{
class ReplyKeyboardHide : public PRIVATE::ReplyMarkup
{
public:
	ReplyKeyboardHide();
	ReplyKeyboardHide(bool selective);

	~ReplyKeyboardHide();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool selective;
};
} //end namespace block
