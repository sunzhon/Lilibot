
(cl:in-package :asdf)

(defsystem "lilistbot-msg"
  :depends-on (:roslisp-msg-protocol :roslisp-utils )
  :components ((:file "_package")
    (:file "Jy901imu" :depends-on ("_package_Jy901imu"))
    (:file "_package_Jy901imu" :depends-on ("_package"))
  ))