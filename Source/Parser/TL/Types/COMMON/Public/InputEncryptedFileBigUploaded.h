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

	unsigned long long Getid() const
	{
		 return this->id;
	}

	int32 Getparts() const
	{
		 return this->parts;
	}

	int32 GetKeyFingerprint() const
	{
		 return this->key_fingerprint;
	}

private:
	unsigned long long id;
	 int32 parts;
	 int32 key_fingerprint;
};
} //end namespace block
