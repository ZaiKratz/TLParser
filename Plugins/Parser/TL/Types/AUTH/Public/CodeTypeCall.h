#pragma once
#include "Engine.h"

#include "../../../Types/Private/CodeType.h"

//begin namespace block
namespace AUTH
{
class CodeTypeCall : public PRIVATE::CodeType
{
public:
	CodeTypeCall();
	~CodeTypeCall();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
