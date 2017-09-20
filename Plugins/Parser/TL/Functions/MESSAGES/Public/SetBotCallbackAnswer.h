#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class SetBotCallbackAnswer : public TLBaseObject
{
public:
	SetBotCallbackAnswer();
	SetBotCallbackAnswer(bool alert, unsigned long long query_id, FString message, FString url, int32 cache_time);

	~SetBotCallbackAnswer();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool alert;
	 unsigned long long query_id;
	 FString message;
	 FString url;
	 int32 cache_time;
	bool result;
};
} //end namespace block
