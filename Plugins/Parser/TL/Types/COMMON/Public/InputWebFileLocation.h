#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputWebFileLocation : public TLBaseObject
{
public:
	InputWebFileLocation();
	InputWebFileLocation(FString url, unsigned long long access_hash);

	~InputWebFileLocation();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	FString url;
	 unsigned long long access_hash;
};
} //end namespace block
