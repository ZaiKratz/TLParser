#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputFile : public TLBaseObject
{
public:
	InputFile();
	InputFile(unsigned long long id, int32 parts, FString name, FString md5_checksum);

	~InputFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 int32 parts;
	 FString name;
	 FString md5_checksum;
};
} //end namespace block
