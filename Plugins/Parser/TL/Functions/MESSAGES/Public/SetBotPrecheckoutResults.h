#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace MESSAGES
{
class SetBotPrecheckoutResults : public TLBaseObject
{
public:
	SetBotPrecheckoutResults();
	SetBotPrecheckoutResults(bool success, unsigned long long query_id, FString error);

	~SetBotPrecheckoutResults();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	bool success;
	 unsigned long long query_id;
	 FString error;
	bool result;
};
} //end namespace block
