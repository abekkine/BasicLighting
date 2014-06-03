#!/bin/bash

TITLE=$1

if [[ "$TITLE" = "" ]] ; then
	echo "No title provided."
	exit 1
fi

DATE=$(date '+%Y-%m-%d')
TIME=$(date '+%H:%M')

LOWERTITLE=${TITLE,,}
DASHTITLE=${LOWERTITLE// /-}

FILENAME=$DATE"-"$DASHTITLE".markdown"

pushd . &> /dev/null
cd _posts

echo "---" > $FILENAME
echo "layout: post" >> $FILENAME
echo "title: $TITLE" >> $FILENAME
echo "date:   $DATE $TIME" >> $FILENAME
echo "---" >> $FILENAME
echo "" >> $FILENAME

popd &> /dev/null
