#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace HELP
{
class AppUpdate : public TLBaseObject
{
public:
	AppUpdate();
	AppUpdate(int32 id, bool critical, FString url, FString text);

	~AppUpdate();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 id;
	 bool critical;
	 FString url;
	 FString text;
};
} //end namespace block
