#pragma once
#include "Engine.h"

#include "../../../Types/Private/CodeType.h"

//begin namespace block
namespace AUTH
{
class CodeTypeSms : public PRIVATE::CodeType
{
public:
	CodeTypeSms();
	~CodeTypeSms();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
};
} //end namespace block
