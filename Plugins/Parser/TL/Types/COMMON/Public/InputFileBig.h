#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFile.h"

//begin namespace block
namespace COMMON
{
class InputFileBig : public TLBaseObject
{
public:
	InputFileBig();
	InputFileBig(unsigned long long id, int32 parts, FString name);

	~InputFileBig();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 int32 parts;
	 FString name;
};
} //end namespace block
