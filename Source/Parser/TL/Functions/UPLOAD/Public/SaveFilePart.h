#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

//begin namespace block
namespace UPLOAD
{
class SaveFilePart : public TLBaseObject
{
public:
	SaveFilePart();
	SaveFilePart(unsigned long long file_id, int32 file_part, TArray<uint8> bytes);

	~SaveFilePart();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	unsigned long long GetFileId() const
	{
		 return this->file_id;
	}

	int32 GetFilePart() const
	{
		 return this->file_part;
	}

	TArray<uint8>  Getbytes() const
	{
		 return this->bytes;
	}

	bool GetResult() const
	{
		 return this->result;
	}

private:
	unsigned long long file_id;
	 int32 file_part;
	 TArray<uint8> bytes;
	bool result;
};
} //end namespace block