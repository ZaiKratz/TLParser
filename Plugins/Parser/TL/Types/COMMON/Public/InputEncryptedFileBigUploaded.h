#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputEncryptedFile.h"

//begin namespace block
namespace COMMON
{
class InputEncryptedFileBigUploaded : public TLBaseObject
{
public:
	InputEncryptedFileBigUploaded();
	InputEncryptedFileBigUploaded(unsigned long long id, int32 parts, int32 key_fingerprint);

	~InputEncryptedFileBigUploaded();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;
private:
	unsigned long long id;
	 int32 parts;
	 int32 key_fingerprint;
};
} //end namespace block
