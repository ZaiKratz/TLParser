#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputFileLocation.h"

//begin namespace block
namespace COMMON
{
class InputEncryptedFileLocation : public TLBaseObject
{
public:
	InputEncryptedFileLocation();
	InputEncryptedFileLocation(unsigned long long id, unsigned long long access_hash);

	~InputEncryptedFileLocation();
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
