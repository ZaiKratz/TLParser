#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace ACCOUNT
{
class CheckUsername : public TLBaseObject
{
public:
	CheckUsername();
	CheckUsername(FString username);

	~CheckUsername();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString username;
	bool result;
};
} //end namespace block
