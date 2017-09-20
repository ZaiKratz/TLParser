#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class Error : public TLBaseObject
{
public:
	Error();
	Error(int32 code, FString text);

	~Error();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	int32 code;
	 FString text;
};
} //end namespace block
