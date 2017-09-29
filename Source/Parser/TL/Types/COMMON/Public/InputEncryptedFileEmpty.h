#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedFile.h"

//begin namespace block
namespace COMMON
{
class InputEncryptedFileEmpty : public TLBaseObject
{
public:
	InputEncryptedFileEmpty();
	~InputEncryptedFileEmpty();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block
