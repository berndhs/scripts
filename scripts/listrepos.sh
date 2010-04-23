#!/bin/bash

LISTFILE=/gitrepos/repolist
echo '# git repo list' > ${LISTFILE}
for gd in /gitrepos/*.git ; do
  echo 'repo.url=http:/pirx' >> ${LISTFILE}
  echo "repo.path=/gitrepo/${gd}" >> ${LISTFILE}
  echo "repo.desc=${gd}" >> ${LISTFILE}
  echo 'repo.owner=bernd@pirx' >> ${LISTFILE}
  echo 'repo.readme=/gitrepo/README' >> ${LISTFILE}
done
  
