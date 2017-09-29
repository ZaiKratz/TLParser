#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace UPLOAD
{
class CdnFile : public TLBaseObject
{
public:
	CdnFile();
	CdnFile(TArray<uint8> bytes);

	~CdnFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	TArray<uint8>  Getbytes() const
	{
		 return this->bytes;
	}

private:
	TArray<uint8> bytes;
};
} //end namespace block
