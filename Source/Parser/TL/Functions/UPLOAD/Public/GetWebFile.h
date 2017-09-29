#pragma once
#include "Engine.h"
#include "../../../TLObjectBase.h"

#include "../../../Types/Common/Public/InputWebFileLocation.h"
#include "../../../Types/Upload/Public/WebFile.h"

//begin namespace block
namespace UPLOAD
{
class GetWebFile : public TLBaseObject
{
public:
	GetWebFile();
	GetWebFile(COMMON::InputWebFileLocation* location, int32 offset, int32 limit);

	~GetWebFile();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

	COMMON::InputWebFileLocation*  Getlocation() const
	{
		 return this->location;
	}

	int32 Getoffset() const
	{
		 return this->offset;
	}

	int32 Getlimit() const
	{
		 return this->limit;
	}

	UPLOAD::WebFile* GetResult() const
	{
		 return this->result;
	}

private:
	COMMON::InputWebFileLocation* location;
	 int32 offset;
	 int32 limit;
	UPLOAD::WebFile* result;
};
} //end namespace block
