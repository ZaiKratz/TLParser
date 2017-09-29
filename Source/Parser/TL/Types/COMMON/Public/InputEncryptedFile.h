#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace COMMON
{
class InputEncryptedFile : public TLBaseObject
{
public:
	InputEncryptedFile();
	InputEncryptedFile(unsigned long long id, unsigned long long access_hash);

	~InputEncryptedFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long Getid() const
	{
		 return this->id;
	}

	unsigned long long GetAccessHash() const
	{
		 return this->access_hash;
	}

private:
	unsigned long long id;
	 unsigned long long access_hash;
};
} //end namespace block
